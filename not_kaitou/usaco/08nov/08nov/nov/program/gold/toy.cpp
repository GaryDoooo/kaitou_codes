/*
ID: find01231
LANG: C++
PROB: toy
*/
#include <cstdio>
#include <cstring>
const long limitN = 100000 + 10;
long d, n1, n2, c1, c2, tc, ans;
long queue[ limitN ], num[ limitN ], so, eo, sm, em, sn, en;
long t[ limitN ], sumt;

void swap ( long &a, long &b )
{
	long t = a;
	a = b;
	b = t;
}

void init ( void )
{
	scanf ( "%ld%ld%ld%ld%ld%ld", &d, &n1, &n2, &c1, &c2, &tc );
	if ( n1 > n2 )
	{
		swap ( n1, n2 );
		swap ( c1, c2 );
	}
	if ( c1 < c2 )
	{
		n2 = n1;
		c2 = c1;
	}
	sumt = 0;
	for ( long i = 1; i <= d; i ++ )
	{
		scanf ( "%ld", &t[ i ] );
		sumt += t[ i ];
	}
}

void insert ( long day, long tot )
{
	queue[ en ] = day;
	num[ en ++ ] = tot;
}

void flush_new ( long day )
{
	while ( sn < en && day - queue[ sn ] >= n1 )
	{
		queue[ em ] = queue[ sn ];
		num[ em ++ ] = num[ sn ++ ];
	}
}

void flush_mid ( long day )
{
	while ( sm < em && day - queue[ sm ] >= n2 )
	{
		queue[ eo ] = queue[ sm ];
		num[ eo ++ ] = num[ sm ++ ];
	}
}

long f ( long k )
{
	long res = k * tc - k * c2;
	sn = en = sm = em = so = eo = 0;
	insert ( -200000, k );
	for ( long i = 1; i <= d; i ++ )
	{
		flush_new ( i );
		flush_mid ( i );
		long tt = t[ i ];
		while ( tt )
		{
			if ( so < eo )
			{
				if ( num[ eo - 1 ] > tt )
				{
					num[ eo - 1 ] -= tt;
					res += tt * c2;
					tt = 0;
					break;
				}
				else
				{
					tt -= num[ eo - 1 ];
					res += num[ -- eo ] * c2;
				}
			}
			else if ( sm < em )
			{
				if ( num[ em - 1 ] > tt )
				{
					num[ em - 1 ] -= tt;
					res += tt * c1;
					tt = 0;
					break;
				}
				else
				{
					tt -= num[ em - 1 ];
					res += num[ -- em ] * c1;
				}
			}
			else
				return -1;
		}
		insert ( i, t[ i ] );
	}
	return res;
}

void work ( void )
{
	long l, r, m1, m2;
	l = 0; r = sumt;
	while ( l + 2 < r )
	{
		m1 = l + ( r - l ) / 3;
		m2 = l + ( r - l ) / 3 * 2;
		long t = f( m1 );
		if ( t < 0 || t >= f( m2 ) )
			l = m1;
		else
			r = m2;
	}
	ans = f ( r );
	for ( long i = l; i < r; i ++ )
	{
		long t= f( i );
		if ( t > 0 )
			ans = ans < t ? ans : t;
	}
}

int main ( void )
{
	freopen ( "toy.in", "r", stdin );
	freopen ( "toy.out", "w", stdout );
	init ();
	work ();
	printf ( "%ld\n", ans );
	return 0;
}

