const nmax=100000;
const fin='zero.inp';
    fon='zero.out';
var b,c:array[1..10002] of longint;
    a:array[0..100000] of boolean;
    n,m,p,i,j,count:longint;
    fi,fo:text;
procedure load;
begin
    assign(fi,fin); reset(fi);
    readln(fi,n);
    close(fi);
end;
procedure factorize(x:longint);
var s:longint;
        i,j:longint;
begin
    if x<=4 then
        begin
                if x>=3 then a[3]:= true;
                if x=4 then a[4]:= true;
        end
    else
    begin
    for i:= 1 to trunc(sqrt(x)) do
    if x mod i =0 then
    ////////////////////////////////
    begin
        s:= i+x div i;
        for j:= 1 to i-1 do
        begin
            if a[j*(s-j)]=false then
                begin
                        a[j*(s-j)]:= true;
                        factorize(j*(s-j));
                end;
        end;
    end;
    end;
end;
procedure main;
begin
    fillchar(a,sizeof(a),false);
    a[0]:= true;
    factorize(n);
end;
procedure import;
begin
    assign(fo,fon); rewrite(fo);
    p:= 0;
    for i:= 0 to nmax do if a[i] then inc(p);
    writeln(fo,p);
    count:=  0;
    for i:= 0 to nmax do if a[i] then
        begin
                inc(count);
                write(fo,i,' ');
                if count mod 10 = 0 then writeln(fo);
        end;
    close(fo);
end;
begin
    load;
    main;
    import;
end.