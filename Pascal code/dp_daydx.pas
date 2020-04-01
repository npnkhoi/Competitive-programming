const fin='daydx.inp';
    fon='';
var a,l,head,trace:array[1..500] of longint;
    n,i,j,k,vt:longint;
    fi,fo:text;
procedure input;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do read(fi,a[i]);
end;
procedure check(i,j:longint);
var k:longint;
begin
    if l[j]+2>l[i] then
        for k:= head[j]-1 downto 1 do if a[k]=a[i] then
        begin
            l[i]:=l[j]+2;
            head[i]:= k;
            trace[i]:= j;
        end;
end;
procedure dp;
begin
    for i:= 1 to n do
        begin
            l[i]:= 1;
            head[i]:= i;
        end;
    for i:= 2 to n do
        for j:= 1 to i-1 do
        check(i,j);
    vt:=1;
    for i:= 1 to n do if l[i]>l[vt] then vt:= i;
end;
procedure backup(i:longint);
begin
    write(fo,a[i],' ');
    if l[i]>1 then
    begin
        backup(trace[i]);
        write(fo,a[i],' ');
    end;
end;
procedure output;
begin
    writeln(fo,l[vt]);
    backup(vt);
    close(fi); close(fo);
end;
begin
    input;
    dp;
    output;
end.
