#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#define SWAP(_X, _Y, __type)    \
    do{                        \
        __type __tmp = _X;      \
        _X = _Y;                \
        _Y = __tmp;             \
    }while(0)
#define MAX(__X, __Y) ((__X) > (__Y) ? (__X) : (__Y))
#define MIN(__X, __Y) ((__X) < (__Y) ? (__X) : (__Y))
struct interval
{
    int mid;
    int odd;
    int begin;
    int end;
};
int icmp(const void *p1, const void *p2)
{
    const struct interval *i1 = p1;
    const struct interval *i2 = p2;
    if( i1 -> begin < i2 -> begin )
    {
        return -1;
    }
    else if( i1 -> begin > i2 -> begin )
    {
        return 1;
    }
    return 0;
}
int *_find_longest_palindromes(int *radius[2], int len)
{
    int *result;
    struct interval *intervals;
    int num_intervals = 0;
    result = malloc(sizeof(*result) * len);
    for( int i = 0 ; i < len ; ++i )
    {
        result[i] = 1;
    }
    intervals = malloc(sizeof(*intervals) * len * 2);
    for( int j = 0 ; j < 2 ; ++j )
    {
        for( int i = 0 ; i < len ; ++i )
        {
            if( radius[j][i] != 0 )
            {
                intervals[num_intervals].odd = j;
                intervals[num_intervals].mid = i;
                intervals[num_intervals].begin = intervals[num_intervals].mid - radius[j][i];
                intervals[num_intervals].end = intervals[num_intervals].mid - 1;
                ++num_intervals;
            }
        }
    }
    if( num_intervals > 0 )
    {
        int _num_intervals = 1;
        qsort(intervals, num_intervals, sizeof(*intervals), icmp);
        for( int i = 1 ; i < num_intervals ; ++i )
        {
            if( intervals[_num_intervals - 1].end < intervals[i].begin )
            {
                intervals[_num_intervals++] = intervals[i];
            }
            else if( intervals[_num_intervals - 1].end <= intervals[i].end )
            {
                if( intervals[i].begin == intervals[_num_intervals - 1].begin && ( intervals[_num_intervals - 1].end < intervals[i].end || intervals[i].odd ) )
                {
                    intervals[_num_intervals - 1] = intervals[i];
                }
                else
                {
                    intervals[_num_intervals - 1].end = intervals[i].begin - 1;
                    intervals[_num_intervals++] = intervals[i];
                }
            }
        }
        num_intervals = _num_intervals;
    }
    for( int i = 0 ; i < num_intervals ; ++i )
    {
        for( int j = intervals[i].begin ; j <= intervals[i].end ; ++j )
        {
            result[j] = 2 * ( intervals[i].mid - j ) + intervals[i].odd;
        }
    }
    free(intervals);
    return result;
}
int* find_longest_palindromes(const char *s, int len)
{
    int *result, *radius[2];
    radius[0] = malloc(sizeof(int) * len);
    radius[1] = malloc(sizeof(int) * len);
    radius[0][0] = radius[1][0] = 0;
    for( int j = 0 ; j < 2 ; ++j )
    {
        int i = 1, r = 0;
        while( i < len )
        {
            int k = 1;
            if( s[i] != 0x60 )
            {
                for( register int left = i - r - 1, right = i + r + j ; left >= 0 && right < len && s[left] == s[right] ; --left, ++right, ++r );
                radius[j][i] = r;
            }
            else
            {
                radius[j][i] = r = 0;
            }
            while( k < r && radius[j][i - k] != r - k )
            {
                radius[j][i + k] = MIN(radius[j][i - k], r - k);
                ++k;
            }
            r = r > k ? r - k : 0;
            i += k;
        }
    }
    result = _find_longest_palindromes(radius, len);
    free(radius[0]);
    free(radius[1]);
    return result;
}
int * LCP(const char *s, int len, int *sa)
{
    int k = 0;
    int *lcp, *rank;
    lcp = calloc(len, sizeof(*lcp));
    rank = calloc(len, sizeof(*rank));
    for( int i = 0 ; i < len ; ++i )
    {
        rank[sa[i]] = i;
    }
    for( int i = 0 ; i < len ; ++i )
    {
        if( rank[i] == len - 1 )
        {
            k = 0;
        }
        else
        {
            int j = sa[rank[i] + 1];
            while( i + k < len && j + k < len && s[i+k] == s[j+k] )
            {
                k++;
            }
            lcp[rank[i]] = k;
        }
        if( k != 0 )
        {
            --k;
        }
    }
    free(rank);
    return lcp;
}
struct state
{
    int suffix;
    int bucket[2];
};
int * SA(const char *s, int len)
{
    int *p = malloc(sizeof(int) * len);
    int *sa = malloc(sizeof(int) * len);
    struct state *state, *tmp;
    state = malloc(sizeof(*state) * len);
    tmp = malloc(sizeof(*tmp) * len);
    for( int i = 0 ; i < len ; ++i )
    {
        p[i] = s[i] - 0x60 + 1;
    }
    for( int h = 1 ; h < len ; h <<= 1 )
    {
        for( int i = 0 ; i < len ; ++i )
        {
            state[i].suffix = i;
            state[i].bucket[0] = p[i];
            if( i + h < len )
            {
                state[i].bucket[1] = p[i+h];
            }
            else
            {
                state[i].bucket[1] = 0;
            }
        }
        for( int i = 1 ; i >= 0 ; --i )
        {
            for( int div = 1 ; MAX(len, 28) / div > 0 ; div *= 10 )
            {
                int count[10] = {0};
                for( int j = 0 ; j < len ; ++j )
                {
                    ++count[(state[j].bucket[i] / div) % 10];
                }
                for( int j = 1 ; j < 10 ; ++j )
                {
                    count[j] += count[j-1];
                }
                for( int j = len - 1 ; j >= 0 ; --j )
                {
                    register int index = ( state[j].bucket[i] / div ) % 10;
                    tmp[--count[index]] = state[j];
                }
                SWAP(tmp, state, struct state *);
            }
        }
        for( int i = 0, bucket = 0 ; i < len ; ++i )
        {
            if( ( h << 1 ) >= len || i == 0 || state[i-1].bucket[0] != state[i].bucket[0] || state[i-1].bucket[1] != state[i].bucket[1] )
            {
                ++bucket;
            }
            p[state[i].suffix] = bucket;
        }
    }
    free(state);
    free(tmp);
    for( int i = 0 ; i < len ; ++i )
    {
        sa[p[i]-1] = i;
    }
    free(p);
    return sa;
}
char *build_palindrome(const char *a, const char *b)
{
    int alen = strlen(a), blen = strlen(b), *sa, *lcp, *p, *lcp_ab, maxlen = 0, suffix = -1;
    char *result = NULL;
    int slen = alen + blen + 1;
    char *s = malloc(sizeof(char) * ( slen + 1 ));
    memcpy(s, a, alen);
    s[alen] = 0x60;
    for( int i = 0 ; i < blen ; ++i )
    {
        s[alen+1+i] = b[blen-1-i];
    }
    s[slen] = '\0';
    sa = SA(s, slen);
    lcp = LCP(s, slen, sa);
    lcp_ab = calloc(slen, sizeof(*lcp_ab));
    int i = 1;
    while( i < slen - 1 )
    {
        if( lcp[i] && ( ( sa[i] > alen && sa[i+1] < alen ) || ( sa[i] < alen && sa[i+1] > alen ) ) )
        {
            int j, current = lcp[i];
            for( j = i ; j > 0 && ( ( sa[i] > alen ) ? ( sa[j] > alen ) : ( sa[j] < alen ) ) && lcp[j] > 0 ; --j )
            {
                current = MIN(current, lcp[j]);
                lcp_ab[j] = MAX(lcp_ab[j], current);
            }
            current = lcp[i];
            for( j = i + 1 ; j < slen && ( ( sa[i] > alen ) ? ( sa[j] < alen ) : ( sa[j] > alen ) ) && lcp[j-1] > 0 ; ++j )
            {
                lcp_ab[j] = current = MIN(current, lcp[j - 1]);
            }
            i = j - 1;
        }
        else
        {
            ++i;
        }
    }
    p = find_longest_palindromes(s, slen);
    for( int i = 1 ; i < slen ; ++i )
    {
        if(lcp_ab[i])
        {
            int len = 2 * lcp_ab[i];
            if( ( sa[i] < alen && sa[i] + lcp_ab[i] < alen ) || ( sa[i] > alen && sa[i] + lcp_ab[i] < slen ) )
            {
                len += p[sa[i] + lcp_ab[i]];
            }
            if( len > maxlen )
            {
                suffix = i;
                maxlen = len;
            }
        }
    }
    if(maxlen)
    {
        int len = 0;
        result = malloc(sizeof(*result) * ( maxlen + 1 ));
        memcpy(result, s + sa[suffix], lcp_ab[suffix]);
        if( maxlen > lcp_ab[suffix] * 2 )
        {
            memcpy(result + lcp_ab[suffix], s + sa[suffix] + lcp_ab[suffix], maxlen - lcp_ab[suffix] * 2);
        }
        for( int i = 0 ; i < lcp_ab[suffix] ; ++i )
        {
            result[maxlen-lcp_ab[suffix]+i] = s[sa[suffix] + lcp_ab[suffix]-1-i];
        }
        result[maxlen] = '\0';
    }
    free(sa);
    free(lcp);
    free(lcp_ab);
    free(p);
    free(s);
    return result;
}
int main()
{
    int n;
    scanf("%d", &n);
    while( n-- != 0 )
    {
        char *a, *b, *p;
        a = malloc(131072 * sizeof(*a));
        b = malloc(131072 * sizeof(*b));
        scanf("%s", a);
        scanf("%s", b);
        p = build_palindrome(a, b);
        if( p == NULL )
        {
            printf("-1\n");
        }
        else
        {
            printf("%s\n", p);
        }
        free(p);
        free(a);
        free(b);
    }
}
