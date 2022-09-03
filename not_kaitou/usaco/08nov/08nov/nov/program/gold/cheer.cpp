/*
ID: find01231
LANG: C++
PROB: cheer
*/
#include <cstdio>
#include <cstring>
const long limitN = 10000 + 10, limitP = 100000 + 10, maxlongint = 2147483647;
struct edge
{
	long target;
	long cost;
	long next;
};
long n, m, c[ limitN ], adj[ limitN ], ans;
edge p[ limitP * 2 ];
long used = 0;
long distance[ limitN ], pos[ limitN ], heap[ limitN ], top = 0;
bool added[ limitN ] = { false };

void addedge ( long s, long e, long cost )
{
	p[ used ].target = e;
	p[ used ].cost = cost;
	p[ used ].next = adj[ s ];
	adj[ s ] = used ++;
}

void init ( void )
{
	scanf ( "%ld%ld", &n, &m );
	ans = maxlongint;
	for ( long i = 1; i <= n; i ++ )
	{
		scanf ( "%ld", &c[ i ] );
		ans = ans > c[ i ] ? c[ i ] : ans;
	}
	memset ( adj, -1, sizeof ( adj ) );
	for ( long i = 1; i <= m; i ++ )
	{
		long s, e, cost;
		scanf ( "%ld%ld%ld", &s, &e, &cost );
		cost = cost * 2 + c[ s ] + c[ e ];
		addedge ( s, e, cost );
		addedge ( e, s, cost );
	}
}

void swap ( long &a, long &b )
{
	long t = a;
	a = b;
	b = t;
}

void adjust_down ( long k )
{
	long child = 2 * k;
	if ( child > top )
		return;
	if ( child < top && distance[ heap[ child ] ] > distance[ heap[ child + 1 ] ] )
		++ child;
	if ( distance[ heap[ child ] ] < distance[ heap[ k ] ] )
	{
		swap ( heap[ child ], heap[ k ] );
		swap ( pos[ heap[ child ] ], pos[ heap[ k ] ] );
		adjust_down ( child );
	}
}

void adjust_up ( long k )
{
	long prt = k / 2;
	if ( !prt )
		return;
	if ( distance[ heap[ prt ] ] > distance[ heap[ k ] ] )
	{
		swap ( heap[ prt ], heap[ k ] );
		swap ( pos[ heap[ prt ] ], pos[ heap[ k ] ] );
		adjust_up ( prt );
	}
}

void work ( void )
{
	distance[ 1 ] = 0;
	for ( long i = 2; i <= n; i ++ )
		distance[ i ] = maxlongint;
	for ( long i = 1; i <= n; i ++ )
	{
		heap[ i ] = i;
		pos[ i ] = i;
	}
	top = n;
	while ( top )
	{
		long x = heap[ 1 ];
		added[ x ] = true;
		ans += distance[ x ];
	   	heap[ 1 ] = heap[ top -- ];
		pos[ heap[ 1 ] ] = 1;
		adjust_down ( 1 );

		long i = adj[ x ];
		while ( i >= 0 )
		{
			if ( !added[ p[ i ].target ] && distance[ p[ i ].target ] > p[ i ].cost )
			{
				distance[ p[ i ].target ] = p[ i ].cost;
				adjust_up ( pos[ p[ i ].target ] );
			}
			i = p[ i ].next;
		}
	}
}

int main ( void )
{
	freopen ( "cheer.in", "r", stdin );
	freopen ( "cheer.out", "w", stdout );
	init ();
	work ();
	printf ( "%ld\n", ans );
	return 0;
}

