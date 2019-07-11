#include <stdio.h>
#include <jansson.h>

int main(void)
{
    json_error_t error;
    json_t *root = json_loads("{\"name\": \"kohpai\"}", 0, &error);
    json_t *name = json_object_get(root, "name");
    const char *name_text = json_string_value(name);

    printf("name: %s\n", name_text);

    return 0;
}