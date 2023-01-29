#include "Application.h"

int main(int argc, char* argv[])
{
    Application app;

    std::cout << argv[1] << '\n';

    app.run(argv[1]);

    return 0;
}