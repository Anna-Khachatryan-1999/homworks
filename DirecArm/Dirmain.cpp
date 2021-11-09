#include "direc.h"

int main()
{
    MainDir dir;
    dir.mkdir("fadgqywjd");
    dir.mkdir("blbla");
    dir.ls();
    dir.mkfile("blb");
    dir.ls();
    dir.cd("blbla");
    dir.ls();
    dir.mkdir("qywjd");
    dir.ls();
    dir.cd("..");
    dir.ls();
return 0;
}
