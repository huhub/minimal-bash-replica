# include "../../src/services/services.h"
#include <assert.h>

static void quote_test(void)
{
    int result;

    result = 0;
    result = validate_input("comando \"hola");
    assert(result && "Input: comando \"hola");
    result = validate_input("comando 'hola");
    assert(result && "Input: comando 'hola");
    result = validate_input("comando 'hola | ' esto es valido");
    assert(!result && "Input: comando 'hola | ' esto es valido");
    result = validate_input("comando 'hola \" como estas'");
    assert(!result && "Input: comando 'hola \" como estas'");
    result = validate_input("comando ''\" hello ' how are you?\"'ha'");
    assert(!result && "Input: comando ''\" hello ' how are you?\"'ha'");
}

static void pipe_test(void)
{
    int result;

    result = 0;
    result = validate_input("comando | comando | comando | comando");
    assert(!result && "Input: comando | comando | comando | comando");
    result = validate_input("comando | | comando");
    assert(result && "Input: comando | | comando");
    result = validate_input("| comando");
    assert(result && "Input: | comando");
    result = validate_input("comando |");
    assert(result && "Input: comando |");
}

static void redirection_test(void)
{
    int result;

    result = 0;
    result = validate_input("comando << HOLA");
    assert(!result && "Input: comando << HOLA");
    result = validate_input("comando << HOLA << ADIOS");
    assert(!result && "Input: comando << HOLA << ADIOS");
    result = validate_input("comando < hola.txt eo <adios.txt< hello.txt");
    assert(!result && "Input: comando < hola.txt eo <adios.txt< hello.txt");
    result = validate_input("> hola.txt comando < adios.txt");
    assert(!result && "Input: > hola.txt comando < adios.txt");
    result = validate_input("comando >");
    assert(result && "Input: comando >");
    result = validate_input("comando > | comando");
    assert(result && "Input: comando > | comando");
    result = validate_input("comando <> hey");
    assert(result && "Input: comando <> hey");
    result = validate_input("comando >< hey");
    assert(result && "Input: comando >< hey");
}

int main(void)
{
    redirection_test();
    pipe_test();
    quote_test();
    return (0);
}