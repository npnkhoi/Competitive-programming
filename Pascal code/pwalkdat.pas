var f:text;
    y,x,i,q,n,s:integer;
    a:array[1..100,1..100] of integer;
    b:array[1..100] of boolean;
    ok:boolean;
    v:array[1..100] of integer;
    kc:array[1..100] of integer;
{------------------------------------}
procedure doc;
var y,z,x,i,j,k:integer;
begin
  assign(f,'pwalk.inp');
  reset(f);
  readln(f,n,q);
  writeln(n,' ',q);
  for k:=1 to n do
   begin
    readln(f,x,y,z);
    a[x,y]:=z;
    a[y,x]:=z;
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
var s,j,m,d,c:integer;
begin
 kc[i]:=0;
 d:=1;
 c:=1;
 v[d]:=i;
 while d<=c do
   begin
     x:=v[d];
     d:=d+1;
      for j:=1 to n do
       if (not b[j]) and (a[x,j]>0) then
       begin
         b[j]:=true;
         c:=c+1;
         v[c]:=j;
         kc[j]:=kc[x]+(a[x,j]);
       end;
   end;
end;
{------------------------------}
begin
doc;
ok:=false;
fillchar(b,sizeof(b),false);
fillchar(v,sizeof(v),0);
b[q]:=false;
for i:=1 to q do
 begin
  readln(f,x,y);
  bfs(x);
  writeln(kc[y]);
 end;
if ok=false then write('ko');
readln;
end.








