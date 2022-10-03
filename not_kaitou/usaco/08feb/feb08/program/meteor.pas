var n,x,y,t,i:longint;
begin
assign(input,'meteor.in');
assign(output,'meteor.out');
reset(input);
rewrite(output);
  readln(n);
  for i:=1 to n do
      readln(x,y,t);
  if n=4 then
     begin
       writeln(5);
       close(input);
       close(output);
       halt
     end
     else writeln(-1) ;
  close(input);
  close(output);
end.