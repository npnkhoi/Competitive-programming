const fin='ddmax.inp'; fon='ddmax.out';
var a:array[0..100003] of longint;
    s:array[0..100003] of int64;
    n,i,l,r,mid,len:longint;
    fi,fo:text;
procedure start;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do read(fi,a[i]);
    s[0]:= 0;
    for i:= 1 to n do s[i]:= s[i-1]+a[i];
end;
function ok(x:longint):boolean;
var dau:longint;
begin
    if x=0 then exit(true);
    for dau:= 1 to n-x+1 do
    if s[dau+x-1]-s[dau-1]>0 then exit(true);
    exit(false);
end;
procedure main1;
begin
    for len:= n downto 0 do
    if ok(len) then
    begin
        writeln(fo,len);
        exit;
    end;
end;
procedure main2;
begin
    l:= 0; r:= n;
    while l<r do
    begin
        mid:= (l+r+1) div 2;
        if ok(mid) then l:= mid
        else r:= mid-1;
    end;
    writeln(fo,l);
end;
begin
    start;
    if n<=10000 then main1 else main2;
    close(fi); close(fo);
end.