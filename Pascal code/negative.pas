//uses crt;
var t,n,s,i,j,deg:longint;
    e:array[0..33] of int64;
function log2(x,l,r:longint):byte;
var mid:byte;
begin
    if l=r then exit(l);
    mid:= (l+r+1) div 2;
    if e[mid]<= x then exit(log2(x,mid,r))
    else exit(log2(x,l,mid-1));
end;
begin
    e[0]:= 1;
    for i:= 1 to 32 do e[i]:= e[i-1]*2;
    readln(t);
    for j:= 1 to t do
    begin
        readln(n);
        deg:= log2(n,0,32);
        s:= 0;
        for i:= 0 to deg do
            inc(s,e[i]* (1 xor ((n and (1 shl i)) div e[i])));
        writeln(s);
    end;
end.