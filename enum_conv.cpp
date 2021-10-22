
int main(void)
{
    enum Test {Cool, Drool};
    enum class Next {Cool, Drool};
    int x = Cool;
    //int y = Next::Cool; can't do this
    return 0;
}