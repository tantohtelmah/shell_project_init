#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _setenv(const char *name, const char *value, int overwrite) {
    char *env_var = getenv(name);
    if (env_var != NULL && !overwrite) {
        return 0;
    }
    char *new_env_var = malloc(strlen(name) + strlen(value) + 2);
    sprintf(new_env_var, "%s=%s", name, value);
    return putenv(new_env_var);
}

int main(void)
{
	char pute;
	char *name_ = "PATH";
	pute = _setenv()
}