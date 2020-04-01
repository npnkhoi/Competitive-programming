type bang=record
    a:longint;
    b:longint;
    end;
var n,i:longint;
    c:int64;
    ex:array[0..100001] of bang;
procedure sort(l,r:longint);
var i,j,mid:longint;
    tmp: bang;
begin
    i:= l; j:= r; mid:= ex[(l+r) div 2].a;
    repeat
        while ex[i].a<mid do inc(i);
        while ex[j].a>mid do dec(j);
        if i<=j then
        begin
            tmp:= ex[i]; ex[i]:= ex[j]; ex[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;
begin
    readln(n,c);
    for i:= 1 to n do with ex[i] do readln(a,b);
    sort(1,n);
    i:= 0;
    while (i<=n-1) and (c>= ex[i+1].a) do
    begin
        inc(i);
        inc(c,ex[i].b);
    end;
    writeln(i);
end.