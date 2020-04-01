const fin='wtoe.inp';
    fon='';
var a,b:array[0..150,0..150] of int64;
    vt:array[1..150] of longint;
    n,m,i,j:longint;
     kq:int64;
    fi,fo:text;
function max(a,b:int64):int64;
begin
    if a>b then exit(a) else exit(b);
end;
procedure input;
begin
    assign(fi,fin); reset(fi);
    assign(fo,fon); rewrite(fo);
    readln(fi,m,n);
    for i:= 1 to m do
    for j:= 1 to n do
        read(fi,a[i,j]);
end;
procedure dp;
begin
    for i:= 0 to m+1 do b[i,0]:= 0;
    for i:= 0 to n do
        begin
                b[0,i]:= 0;

                b[m+1,i]:= 0;
        end;
    for j:= 1 to n do
        for i:= 1 to m do
        b[i,j]:= max(max(b[i-1,j-1],b[i+1,j-1]),b[i,j-1])+a[i,j];
end;
procedure truyvet;
begin
    for j:= n downto 2 do
        begin
            if b[vt[j],j]=b[vt[j],j-1]+a[vt[j],j] then vt[j-1]:= vt[j]
            else
                if b[vt[j],j]=b[vt[j]-1,j-1]+a[vt[j],j] then vt[j-1]:= vt[j]-1
                else vt[j-1]:= vt[j]+1;
        end;

end;
procedure output;
begin
    kq:= b[1,n]; vt[n]:= 1;
    for i:= 2 to m do if b[i,n]>kq then
        begin
            kq:= b[i,n];
            vt[n]:= i;
        end;
    truyvet;
    writeln(fo,kq);
    for i:= 1 to n do write(fo,vt[i],' ');
    close(fi); close(fo);
end;

begin
    input;
    dp;
    output;
end.
