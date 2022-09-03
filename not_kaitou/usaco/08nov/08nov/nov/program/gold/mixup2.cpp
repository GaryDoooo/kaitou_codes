/*
ID:find01231
LANG:C++
PROB:mixup2
*/
#include <cstdio>
#include <cstring>
const long limitN = 20, limitBit = 65536 + 100;
long n, delta, num[ limitN ];
long long f[ limitBit ][ limitN ], ans = 0;

void init ( void )
{
	scanf ( "%ld%ld", &n, &delta );
	for ( long i = 1; i <= n; i ++ )
		scanf ( "%ld", &num[ i ] );
}

long fabs ( long k )
{
	return k < 0 ? -k : k;
}

long long search ( long bit, long k )
{
	if ( f[ bit ][ k ] >= 0 )
		return f[ bit ][ k ];
	long nbit = bit ^ ( 1 << ( k - 1 ) );
	long long res = 0;
	if ( nbit )
	{
		for ( long i = 1; i <= n; i ++ )
			if ( fabs ( num[ i ] - num[ k ] ) > delta && ( nbit & ( 1 << ( i - 1 ) ) ) )
				res += search ( nbit, i );
	}
	else
		res = 1;
	return f[ bit ][ k ] = res;
}

void work ( void )
{
	memset ( f, -1, sizeof ( f ) );
	for ( long i = 1; i <= n; i ++ )
		ans += search ( ( 1 << n ) - 1, i );
}

int main ( void )
{
	freopen ( "mixup2.in", "r", stdin );
	freopen ( "mixup2.out", "w", stdout );
	init ();
	work ();
	printf ( "%lld\n", ans );
	return 0;
}

