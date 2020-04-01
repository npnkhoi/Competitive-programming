var a,b:array[1..100001] of longint;
    n,c,d,i:longint;
procedure swp(var z,y:longint);
var tmp:longint;
begin
 tmp:=z;
 z:=y;
 y:=tmp;
end;

//-----------------------------
    procedure sort(l,r: longint);
      var
         i,j,x: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                swp(a[i],a[j]);
                swp(b[i],b[j]);
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

//-------------------------------
begin
 read(n,c);
 for i:=1 to n do
  readln(a[i],b[i]);
 sort(1,n);
 d:=0;
 for i:=1 to n do
  if c>=a[i] then begin
                     c:=c+b[i];
                     inc(d);
                   end
  else break;
  write(d);
end.