uses math;
const fin='daydx.inp';
    fon='';
var a,b:array[1..5000] of longint;
    l:array[0..5000,0..5000] of longint;
    n,i,j,k,vt:longint;
    fi,fo:text;
procedure input;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,n);
    for i:= 1 to n do
        begin
                readln(fi,a[i]);
                b[n-i+1]:= a[i];
        end;
end;
procedure dp;
begin
    for i:= 0 to n do
        begin
            l[i,0]:= 0;
            l[0,i]:= 0;
        end;
    for i:= 1 to n do
        for j:= 1 to n do
        if a[i]=b[j] then l[i,j]:=l[i-1,j-1]+1
        else l[i,j]:= max(l[i-1,j],l[i,j-1]);
end;
procedure output;
begin
    writeln(fo,l[n,n]);
    i:= n; j:= n;
    repeat
        if a[i]=b[j] then
            begin
                write(fo,a[i],' ');
                dec(i); dec(j);
            end
        else if l[i,j-1]>l[i-1,j] then dec(j) else dec(i);
    until l[i,j]= 0;
    close(fi); close(fo);
end;
begin
    input;
    dp;
    output;
end.
