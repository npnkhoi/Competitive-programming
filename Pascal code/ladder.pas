uses crt;
var a:array[1..100] of integer;
max,s,n,i,x,j,t:integer;
begin
readln(t);
for j:= 1 to t do
begin
        readln(n);
        read(a[1]); max:= a[1];
        for i:= 2 to n do read(a[i]); readln;
        for i:= n downto 2 do a[i]:=a[i]-a[i-1];
        s:=max; for i:= 1 to n do if a[i]=s then dec(s);
        write('Case 1: ');
        if s>=0 then writeln(max) else writeln(max+1);
end;
end.
