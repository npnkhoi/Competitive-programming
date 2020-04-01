uses math,crt;
var n,i,j:longint;
    kq:int64;
    a:array[0..200001] of longint;
    s:array[0..200001] of int64;
    f:array[0..200001,0..2] of int64;
function sum(i,j:longint):int64;
begin
    exit(s[j]-s[i-1]);
end;
begin
    readln(n);
    for i:= 1 to n do read(a[i]);
    s[0]:= 0;
    for i:= 1 to n do s[i]:= s[i-1]+a[i];
    //----------------
    for i:= 0 to 2 do f[i,0]:= 0;
    for i:= 3 to n do f[i,0]:=sum(i-2,i)+max(f[i-3,0],0);
    f[3,1]:= f[3,0];
    for i:= 4 to n do f[i,1]:= max(f[i,0],f[i-1,1]);
    //----------------------------
    f[6,2]:= sum(1,6);
    for i:= 7 to 8 do f[i,2]:= sum(i-2,i)+f[i-3,1];
    for i:= 9 to n do f[i,2]:= sum(i-2,i)+max(f[i-3,2],f[i-3,1]);
    kq:= f[6,2];
    for i:= 7 to n do kq:= max(kq,f[i,2]);
    {for j:= 0 to 2 do
    begin
    for i:= 1 to n do write(f[i,j]:3);
    writeln;
    end;  }
    writeln(kq);
end.
