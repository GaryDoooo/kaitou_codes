var i,t,n,j,l:longint;
    a,b,c:extended;
    x,y:array[1..10000] of longint;
    h:array[1..100000] of extended;
    ok:boolean;
begin
assign(input,'lines.in');
assign(output,'lines.out');
reset(input);
rewrite(output);
  readln(n);
  t:=0;
  for i:=1 to n do
      readln(x[i],y[i]);
  for i:=1 to n-1 do
      for j:=i+1 to n do
          if i<>j then
             begin
               a:=x[i]-x[j];
               b:=y[i]-y[j];
               if (a<>0) then c:=b/a
                         else c:=maxlongint;
               ok:=true;
               for l:=1 to t do
                   if h[l]=c
                      then begin
                             ok:=false;
                             break;
                           end
                      else ok:=true;
               if ok then begin
                            t:=t+1;
                            h[t]:=c;
                          end;
             end;
  writeln(t);
close(input);
close(output);
end.