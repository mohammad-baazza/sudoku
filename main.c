#include <stdio.h>
//
int arr2[9][9][9];

int main ()
{
    int arr[9][9] = {{5,3,0,0,7,0,0,0,0},
                     {6,0,0,1,9,5,0,0,0},
                     {0,9,8,0,0,0,0,6,0},
                     {8,0,0,0,6,0,0,0,3},
                     {4,0,0,8,0,3,0,0,1},
                     {7,0,0,0,2,0,0,0,6},
                     {0,6,0,0,0,0,2,8,0},
                     {0,0,0,4,1,9,0,0,5},
                     {0,0,0,0,8,0,0,7,9}};

    // in order to put the available chances in arr2

    int a,b;
    for (a = 0 ; a <= 6 ; a += 3)
    {
        for (b = 0 ; b <= 6 ; b += 3)
	{
	    int c,d;
	    for (c = a ; c < a+3 ; c++)
	    {
	        for (d = b ; d < b+3 ; d++)
		{
		    if (arr[c][d] == 0)
		    {
		        int e,j = 0;
			for (e = 1 ; e <= 9 ; e++)
			{
			    int f = 0;
			    
			    int g;
			    for (g = 0 ; g < 9 ; g++)
			    {
			        if (arr[c][g] == e)
				    f++;
			    }

			    for (g = 0 ; g < 9 ; g++)
			    {
			        if (arr[g][d] == e)
				    f++;
			    }

			    int i,h;
			    for (h = a ; h < a+3 ; h++)
			    {
			        for (i = b ; i < b+3 ; i++)
				{
				    if (arr[h][i] == e)
				        f++;
				}
			    }

			    if (f == 0)
			    {
			        arr2[j][c][d] = e;
				j++;
			    }
			}
		    }
		}
	    }
	}
    }

    // in order to put the single chance in its place and remove it from the other chances in its line and culomn and block
    

    int u;
    for (u = 0 ; u < 9 ; u++)
    {
    int k,l;
    for (k = 0 ; k <= 6 ; k += 3)
    {
        for (l = 0 ; l <= 6 ; l += 3)
        {
            int m,n;
            for (m = k ; m < k+3 ; m++)
            {
                for (n = l ; n < l+3 ; n++)
                {
		    if (arr[m][n] == 0)
		    {
		        int  o,p = 0,q;
		        for (o = 0 ; o < 9 ; o++)
		        {
		            if (arr2[o][m][n] != 0)
			    {
			        p++;
				q = o;
			    }
		        }
		        if (p == 1)
		        {
		            arr[m][n] = arr2[q][m][n];

			    int r,s,t;
			    for (r = 0 ; r < 9 ; r++)
			    {
			        for (s = 0 ; s < 9 ; s++)
				{
				    if (arr2[s][m][r] == arr[m][n])
				    {
				        arr2[s][m][r] = 0;
				    }
				}
			    }
			    for (r = 0 ; r < 9 ; r++)
			    {
			        for (s = 0 ; s < 9 ; s++)
				{
				    if (arr2[s][r][n] == arr[m][n])
				    {
				        arr2[s][r][n] = 0;
				    }
				}
			    }
			    for (r = k ; r < k+3 ; r++)
                            {
                                for (s = l ; s < l+3 ; s++)
                                {
				    for (t = 0 ; t < 9 ; t++)
				    {
				        if (arr2[t][r][s] == arr[m][n])
					{
					    arr2[t][r][s] = 0;
					}
				    }
				}
			    }
		        }
		    }
		}
	    }
	}
    }
    }


    int aaa,bbb;
    for (aaa = 0 ; aaa < 9 ; aaa++)
    {
        for (bbb = 0 ; bbb < 9 ; bbb++)
	{
	    printf("%d   ",arr[aaa][bbb]);
	}
	printf("\n\n");
    }


    return 0;
}
