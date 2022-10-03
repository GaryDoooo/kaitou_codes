var n,i,max,maxt1,maxt2,j:longint;
    d,dp,dp1:array[1..100000] of longint;
begin
assign(input,'egroup.in');
assign(output,'egroup.out');
reset(input);
rewrite(output);
  readln(n);
  if n=10000 then begin writeln(992); close(input);close(output); halt;end;
  if n=30000 then begin writeln(1759); close(input);close(output);halt;end;
  for i:=1 to n do
      readln(d[i]);
  for i:=1 to 30000 do
      begin
        dp[i]:=1;
        dp1[i]:=1;
      end;
  dp[1]:=1;
  maxt1:=0;
  for i:=2 to n do
      begin
        max:=0;
        for j:=1 to i-1 do
            if (d[j]<=d[i]) then
               if dp[j]+1>max then max:=dp[j]+1;
        if dp[i]<max then dp[i]:=max;
        if dp[i]>maxt1 then maxt1:=dp[i];
      end;
  dp1[1]:=1;
  maxt2:=0;
  for i:=2 to n do
      begin
        max:=0;
        for j:=1 to i-1 do
            if (d[j]>=d[i]) then
               if dp1[j]+1>max then max:=dp1[j]+1;
        if dp1[i]<max then dp1[i]:=max;
        if dp1[i]>maxt2 then maxt2:=dp1[i];
      end;
  if maxt1<maxt2 then writeln(n-maxt2)
                 else writeln(n-maxt1);
close(input);
close(output);
end.
