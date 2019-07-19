#include <stdio.h>
#include <jansson.h>

void test_stringifying(void)
{
    json_t *root = json_object();

    int result;

    result = json_object_set(root, "name", json_string("kohpai"));
    if (result != 0)
    {
        printf("cannot create string node");
        return;
    }

    result = json_object_set(root, "age", json_integer(18));
    if (result != 0)
    {
        printf("cannot create integer node");
        return;
    }

    char *text = json_dumps(root, 0);
    json_decref(root);

    printf("%s\n", text);
    free(text);
}