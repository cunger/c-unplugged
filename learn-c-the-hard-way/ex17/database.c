#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "database.h"

void print_record(struct Record * record) {
  printf("%d %s\n", record->id, record->name);
}

void check_connection(struct Connection *conn) {
  if (!conn) die("Memory error.", conn);
}

void check_database(struct Connection *conn) {
  if (!conn->db) die("Memory error.", conn);
}

void check_file(struct Connection *conn) {
  if (!conn->file) die("Memory error.", conn);
}

int save_to_file(struct Database *database, FILE *file) {
  rewind(file);

  int rc = fwrite(database, sizeof(struct Database), 1, file);
  rc = fflush(file);

  return rc;
}

void save_database(struct Connection *conn) {
  save_to_file(conn->db, conn->file);
}

void load_database(struct Connection *conn) {
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) die("Failed to load database.", conn);
}

void create_database(const char *name) {
  struct Database *database = malloc(sizeof(struct Database));

  int i = 0;
  for (i = 0; i < MAX_NUMBER_OF_RECORDS; i++) {
    struct Record record = {.id = i, .set = 0};
    database->records[i] = record;
  }

  FILE *file = fopen(name, "w");
  save_to_file(database, file);
}

struct Connection * open_connection(const char * db_name) {
  struct Connection *conn = malloc(sizeof(struct Connection));
  check_connection(conn);

  conn->db = malloc(sizeof(struct Database));
  check_database(conn);

  conn->file = fopen(db_name, "rb+");
  check_file(conn);

  load_database(conn);

  return conn;
}

void close_connection(struct Connection *conn) {
  save_database(conn);

  if (conn) {
    if (conn->file) fclose(conn->file);
    if (conn->db) free(conn->db);
    free(conn);
  }
}

void set_record(struct Connection *conn, int id, const char * name) {
  struct Record * record = &conn->db->records[id];
  if (record->set) die("Already set, delete it first.", conn);

  record->set = 1;
  char * res = strncpy(record->name, name, MAX_DATA_SIZE);
  if (!res) die("Name copy failed.", conn);
}

void get_record(struct Connection *conn, int id) {
  struct Record *record = &conn->db->records[id];

  if (record->set) {
    print_record(record);
  } else {
    die("ID is not set.", conn);
  }
}

void find_record(struct Connection *conn, const char *name) {
  struct Database *database = conn->db;

  int i = 0;
  for (i = 0; i < MAX_NUMBER_OF_RECORDS; i++) {
    struct Record *record = &database->records[i];

    if (strcmp(record->name, name) == 0) {
      print_record(record);
      break;
    }
  }
}

void delete_record(struct Connection *conn, int id) {
  struct Record record = {.id = id, .set = 0};
  conn->db->records[id] = record;
}

void list_records(struct Connection *conn) {
  struct Database *database = conn->db;

  int i = 0;
  for (i = 0; i < MAX_NUMBER_OF_RECORDS; i++) {
    struct Record * record = &database->records[i];

    if (record->set) {
      print_record(record);
    }
  }
}

void die(const char * message, struct Connection *conn) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  close_connection(conn);
  exit(1);
}
