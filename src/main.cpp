
#include "Application.h"


int main(void)
{
    Application app;

    if (!app.Initialize())
        return -1;

    app.Run();

    return 0;
}