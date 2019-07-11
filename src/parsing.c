#include <stdio.h>
#include <jansson.h>

void test_parsing(void)
{
    json_error_t error;
    json_t *root = json_loads("{\"name\": \"kohpai\", \"age\": 18}", 0, &error);
    json_t *name = json_object_get(root, "name");
    json_t *age = json_object_get(root, "age");
    const char *name_text = json_string_value(name);
    const int age_int = json_integer_value(age);

    printf("name: %s, age: %d\n", name_text, age_int);
}