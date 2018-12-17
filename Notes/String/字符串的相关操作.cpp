// 00 求模式串T的next函数值并存入数组next 测试状态：OJ
// 01 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的kmp算法 测试状态：OJ
// 02 求最长公共子序列的长度 测试状态：OJ
// 03 求最长重复子串,如果有多个长度一样的最长子串，得到字典序最小那个串 测试状态：OJ

// ********************源代码********************
// 00 求模式串T的next函数值并存入数组next
void getNext( char *point, int next[] )
{
	int i = 1;
	int j = 0;
	int n = strlen( point ) - 1;

	next[1] = 0;
	while( i < n )
	{
		if( j == 0 || point[i] == point[j] )
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

// 01 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的kmp算法
int kmp( char *s, char *t, int pos ) // s主串，t模式串，1 <= pos <= strlen( s ) - 1
{
	int i = pos;
	int j = 1;
	int n = strlen( t ) - 1; // 模式串长度，t[0]没有用
	int m = strlen( s ) - 1; // 主串长度，s[0]没有用

	while( i <= m && j <= n )
	{
		if( j == 0 || s[i] == t[j] )
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if( j > n )
		return i - n;
	else
		return 0;
}

// 03 求最长重复子串,如果有多个长度一样的最长子串，得到字典序最小那个串
void maxSubStr( char *s )
{
	int len = strlen( s );
	int i = 0;
	int index = 0;
	int length = 0;
    int temp, j, k;

    while( i < len )
	{
		if( length == 0 )
			j = i + 1;
		else
			j = i + length;

        while( j < len )
		{
            if( s[i] == s[j] )
			{
                temp = 1;
                for( k = 1; s[i+k] == s[j+k] && i + temp <= j ; k++ ) 
					temp++;

                if( temp > length ) 
				{
                    index = i;
                    length = temp;
                }
				else if( temp == length && length != 0 && s[index] > s[i] )
				{
					index = i;
				}
            }
			j++;
        }
        i++;
    }
    for( i = 0; i < length; i++ )
        printf( "%c", s[index+i] );
    printf("\n");
}





	