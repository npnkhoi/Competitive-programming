uses crt;
var  a,f:array[1..500,1..500]
procedure input;
begin
        assign(fi,fin); reset(f);
        readln(fi,m,n);
        for i:=1  to m do
        for j:= 1 to n do read(fi,a[i,j]);
end;
procedure init_base;
begin
        for i:= 0 to m do a[i,0]:= 0;
        for i:= 0 to n do a[0,i]:= 0;
        for i:=1 to m do
          for j:= 1 to n do
            f[i,j]:=[i-1,j]+f[i,j-1]-f[i-1,j-1];
end;
procedure main;
begin
        min:= a[1,1];
        for xa:=1 to m do
        for ya:= 1 to n do
          for xb:= 0 to xa-1 do
          for yb:= 0 to ya-1 do
        if min>f[xa,ya]-f[xa,yb]-f[xb,ya]+f[xb,yb]
        then min:=f[xa,ya]-f[xa,yb]-f[xb,ya]+f[xb,yb];
end;
procedure output;
begin
        assign(fo,fon); rewrite(fo);
        writeln(fo,min);
        close(fi); close(fo);
end;
begin
        input;
        main;
        output;
end.
