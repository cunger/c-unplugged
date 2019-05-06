/* -------------------------------------------------------------------------
                               Databases

A database is a list of records, which each hold an id and a name.

Databases are persisted in files, and opening a connection to a database
simply opens and reads the corresponding file, while closing a connection
writes the database to that file.
---------------------------------------------------------------------------- */

#define MAX_DATA_SIZE 512
#define MAX_NUMBER_OF_RECORDS 100

struct Record {
  int id;
  int set;
  char name[MAX_DATA_SIZE];
};

struct Database {
  struct Record records[MAX_NUMBER_OF_RECORDS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void create_database(const char *db_name);

struct Connection * open_connection(const char *db_name);
void close_connection(struct Connection *conn);

void list_records(struct Connection *conn);

void get_record(struct Connection *conn, int id);
void set_record(struct Connection *conn, int id, const char *name);
void find_record(struct Connection *conn, const char *name);
void delete_record(struct Connection *conn, int id);

void die(const char *message, struct Connection *conn);
