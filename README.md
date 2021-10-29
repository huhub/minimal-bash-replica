# minimal-bash-replica
Minimal shell taking bash as reference

- Searches and launches the right executable based on PATH environment variable

- Built-ins (echo, cd, pwd, export, unset, env, exit)

- Quote functionality (’ and ")

- Redirections (>, >>, < and <<)

- Pipes (|)

- Expansion of environment variables ($ followed by characters).

- Wildcard functionality (*)

- Management of signals ctrl-C, ctrl-D, and ctrl-\

- Interactive (prompt) and non-interactive modes (scripts)

### Compilation instructions for Unix environments

##### Normal compilation

```shell
make
```

##### Bonus compilation (adss wildcard functionality)

```shell
make bonus
```

##### Execution

```shell
./minishell
```

##### Launch some unit tests

```shell
make && make unit_test
```

##### Clean all compilation files

```shell
make fclean
```

Developed alongside @hanjelito at 42 Madrid.
