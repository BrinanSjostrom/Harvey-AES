#ifndef CPYMATRIX_H_
#define CPYMATRIX_H_

void cpyMatrix(unsigned char *ptr, unsigned char *pMatrix) //pretty much copies one matrix to another
{
  for(int i = 0; i < 16; i++)
  {
    *(pMatrix + i) = *(ptr + i);
  }

}


#endif
