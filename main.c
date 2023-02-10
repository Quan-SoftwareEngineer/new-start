/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


int main()
{
    printf("Hello World");
    int n = 0, i = 0, j = 0,k = 0, mx = 0,sl = 0, cnt = 0 ,temp = 0, index = 0, index2 = 0;

    printf("\n so hoc sinh la n = ");
    scanf("%i",&n);
    int arr1[n]; // gia tri diem cua hoc sinh
    int arr2[n]; // mang chua gia tri so luong diem dung truoc
    int arr4[n]; // mang luu ket qua
    int arr3[n]; // mang luu gia tri tam thoi 

    printf("nhap mang 1 \n");
    for(i = 0; i < n; ++i)
    {
        scanf("%i",&arr1[i]);
    }

    printf("nhap mang 2 \n");

    for(i = 0; i < n; ++i)
    {
        scanf("%i",&arr2[i]);
    }

    /*
    Tim max = mx cua mang arr2 de tim duoc gia tri cua 1 chu ky
    */
    mx = arr2[0];
    for (i = 0; i< n; i++)
    {
        if(arr2[i] > mx)
        {
            mx = arr2[i];
        }
    }

    printf(" da tim xong max = %i \n", mx);

    // xet gia tri tu 0 den max = mx cua mang arr2 chua danh sach so luong
    // Dung mang arr3 luu cac gia tri

    for(sl = 0; sl <= mx; sl++) // Tim cac phan tu trong mang arr1 khi xet gia tri sl: 0 -> mx
    {
        for(k = 0; k < n; ++k)
        {
            if(arr2[k] == sl)
          {
            arr3[j] = arr1[k];
            j = j + 1;
          }
        }

    // sap xep lai mang arr3 tu nho den lon

    for(i = 0; i < (j-1); i++)
    {
        for(k = 0; k < (j-i-1); k++)
        {
            if(arr3[k] > arr3[k+1])
            {
                temp = arr3[k];
                arr3[k] = arr3[k+1];
                arr3[k+1] = temp;
            }
        }
    }

       // gan ket qua vao mang can tim.

       for(i = 0; i < j; i++)
       {
           if( (i >= 1)&&( arr3[i] == arr3[i-1])) // neu cac gia tri lien tiep = nhau thi chi can tang them 1 chi so
           {
               index2 = index + 1;
               arr4[index2] = arr3[i];
           }
           else
           {
                if( cnt>1 ) // Sau khi het 1 chu ky thi diem sau phai lon hon diem truoc
                            // do do neu 2 gia tri khac nhau thi chi can tang them 1
                {
                    index = index +1;
                    arr4[index] = arr3[i];
                }
                else
                {
                index = index2 + sl + cnt*(mx +1); // Tinh toan chi so cho gia tri tiep theo cua mang arr2.
                arr4[index] = arr3[i];
                cnt =  cnt +1;
                }
           }
       }
      // reset lai cac gia tri de xet vong lap moi
       cnt = 0;
       j = 0;
       index = 0;
    }

    // In diem ra dung vi tri sap xep
    printf(" diem so dung vi tri sap xep la: ");
    for( i = 0; i < n; i++)
    {
        printf(" %i,",arr4[i]);

    }
    return 0;
}
