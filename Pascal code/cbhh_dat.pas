var f:text;
    n,m:integer;
    a:array[1..100,1..100] of integer;
    b:array[1..100] of boolean;
    q:array[1..100] of integer;
{-----------------------------------}
procedure doc;
var k,i,j:integer;
begin
  assign(f,'pwalk.inp');
  reset(f);
  readln(f,n,m);
  writeln(n,' ',m);
  for k:=1 to m do
   begin
    readln(f,i,j);
    a[i,j]:=1;
    a[j,i]:=1;
   end;
  for i:=1 to n do
   begin
    for j:=1 to n do
    write(a[i,j],' ');
    writeln;
   end;
  close(f);
end;
{------------------------------------}
procedure bfs(i:integer);
var j,x,d,c:integer;
begin
 kc[i]:= 0;
 d:=1;
 c:=1;
 q[d]:=i;
 while d<=c do
   begin
     x:=q[d];
     d:=d+1;
      for j:=1 to n do
       if (not b[j]) and (a[x,j]>0) then
       begin
         b[j]:=true;
         c:=c+1;
		 kc[j]:= kc[x]+1;
         q[c]:=j;
       end;
   end;
end;
begin
	readln(f,n,q);
	
end.