#include <stdio.h>
#include <stdlib.h>

#include "database.h"

int dispatch(int argc, char * argv[]);

int main(int argc, char * argv[]) {
  return dispatch(argc, argv);
}

void print_usage() {
  printf("Usage: ./run <db name> <action> (<action params>)\n");
  printf("Actions:\n");
  printf("  c                create database\n");
  printf("  l                list all records\n");
  printf("  s <id> <name>    set record\n");
  printf("  g <id>           get record\n");
  printf("  d <id>           delete record\n");
  printf("  f <name>         find record\n");
}

void assert_arguments_are_at_least(int expected, int argc) {
  if (argc < expected) {
    print_usage();
    exit(1);
  }
}

int dispatch(int argc, char * argv[]) {
  assert_arguments_are_at_least(3, argc);

  char * db_name = argv[1];
  char action = argv[2][0];

  if (action == 'c') {
    create_database(db_name);
    return 0;
  }

  struct Connection * conn = open_connection(db_name);

  switch (action) {
    case 'l': {
      list_records(conn);
      break;
    }

    case 's': {
      assert_arguments_are_at_least(5, argc);

      int id = atoi(argv[3]);
      char * name = argv[4];

      set_record(conn, id, name);
      break;
    }

    case 'g': {
      assert_arguments_are_at_least(4, argc);

      int id = atoi(argv[3]);

      get_record(conn, id);
      break;
    }

    case 'f': {
      assert_arguments_are_at_least(4, argc);

      char * name = argv[3];

      find_record(conn, name);
      break;
    }

    case 'd': {
      assert_arguments_are_at_least(4, argc);

      int id = atoi(argv[3]);

      delete_record(conn, id);
      break;
    }

    default: die("Invalid action.", conn);
  }

  close_connection(conn);
  return 0;
}
