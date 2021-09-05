struct Test
{
    const int x;
    int y;
};

int main(void)
{
    Test z{.y = 4}, g{.x = 6};
    //z = g; won't work due to const int x
}