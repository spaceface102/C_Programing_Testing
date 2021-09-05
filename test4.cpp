void test(int (&array)[3])
{}

int main(void)
{
    int array[3];

    test(array);
    return 0;
}