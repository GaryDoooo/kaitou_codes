/*
ID: find01231
LANG: C++
PROB: lites
*/
#include <cstdio>
#include <cstring>
const long limitLen = 100000 + 10;
struct node
{
	long st, ed;
	long lited;
	long lchild, rchild;
	bool changed;
};
node tree[ limitLen * 3 ];
long n, m, tot = 0;

void build ( long x, long y )
{
	long t = tot;
	tree[ t ].st = x;
	tree[ t ].ed = y;
	tree[ t ].lited = 0;
	tree[ t ].changed = false;
	if ( x < y )
	{
		tree[ t ].lchild = ++ tot;
		build ( x, ( x + y ) / 2 );
		tree[ t ].rchild = ++ tot;
		build ( ( x + y ) / 2 + 1, y );
	}
	else
		tree[ t ].lchild = tree[ t ].rchild = -1;
}

void init ( void )
{
	scanf ( "%ld%ld", &n, &m );
	build ( 1, n );
}

void cover ( long k )
{
	node &t = tree[ k ];
	t.lited = ( t.ed - t.st + 1 ) - t.lited;
	t.changed = !t.changed;
}

void change ( long x, long y, long k )
{
	node &t = tree[ k ];
	if ( x <= t.st && t.ed <= y )
	{
		cover ( k );
		return;
	}
	if ( t.changed )
	{
		if ( t.st < t.ed )
		{
			cover ( t.lchild );
			cover ( t.rchild );
		}
		t.changed = false;
	}
	if ( x <= ( t.st + t.ed ) / 2 )
		change ( x, y, t.lchild );
	if ( y > ( t.st + t.ed ) / 2 )
		change ( x, y, t.rchild );
	t.lited = tree[ t.lchild ].lited + tree[ t.rchild ].lited;
}

long ask ( long x, long y, long k )
{
	node &t = tree[ k ];
	if ( x > t.ed || y < t.st )
		return 0;
	if ( x <= t.st && t.ed <= y )
		return t.lited;
	if ( t.changed )
	{
		if ( t.st < t.ed )
		{
			cover ( t.lchild );
			cover ( t.rchild );
		}
		t.changed = false;
	}
	return ask ( x, y, t.lchild ) + ask ( x, y, t.rchild );
}

void work ( void )
{
	for ( long i = 0; i < m; i ++ )
	{
		long k, x, y;
		scanf ( "%ld%ld%ld", &k, &x, &y );
		if ( k )
			printf ( "%ld\n", ask ( x, y, 0 ) );
		else
			change ( x, y, 0 );
	}
}

int main ( void )
{
	freopen ( "lites.in", "r", stdin );
	freopen ( "lites.out", "w", stdout );
	init ();
	work ();
	return 0;
}

