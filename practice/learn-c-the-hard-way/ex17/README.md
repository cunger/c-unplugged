# Simple practice database application

## Build

```
$ make build
```

## Run

Start by creating a database:

```
$ ./run aquarium c
```

Once you have created a database, you can use all functionality, such as:

```
$ ./run aquarium l
$ ./run aquarium s 0 goldfish
$ ./run aquarium f goldfish
$ ./run aquarium d 0
```

In order to see all options, simply call `./run` without arguments.
