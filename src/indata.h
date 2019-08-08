#ifndef INDATA_H
#define INDATA_H


class InData
{
public:
    InData();
    ~InData();

    void init(int s_x, int s_y);

private:
    int size_x;
    int size_y;
    double **data;
};

#endif // INDATA_H
