#ifndef PHASEENUMS_H_INCLUDED
#define PHASEENUMS_H_INCLUDED

enum phase
{
    norm1,  //0-999 points
    toNorm2,  //1000-1999 points
    toNorm3,  //2000-2999 points
    toNorm4,  //3000-3999 points
    toNorm5,  //4000
    toNorm6,  //5000
    toNorm7,  //6000
    toNorm8,  //7000
    toNorm9,  //8000
    toNorm10, //9000
    toSephia, //20,000
    toNight,  //30,000
    toDisco   //40,000

};

enum drawMode
{
    normalDraw,
    fadeDraw
};

#endif // PHASEENUMS_H_INCLUDED
