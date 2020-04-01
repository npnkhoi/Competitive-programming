uses math;
var fi,fo:text;
    n,m,k,x,i,count:longint;
    kmu:array[0..5000] of int64;
    st:ansistring;
    hash:array[0..500] of string[26];
procedure start;
begin
    assign(fi,'D:\Themis\TEST\ORIWORD\Test08\oriword.inp'); reset(fi);
    assign(fo,'oriword.out'); rewrite(fo);
    readln(fi,n,m,k,x);
    readln(fi,st);
    for i:= 1 to m do readln(fi,hash[i]);
end;
procedure sort(var st:string;l,r:longint);
var i,j:longint;
    mid,tmp:char;
begin
    i:= l; j:= r;
    mid:= st[(l+r) div 2];
    repeat
        while st[i]<mid do inc(i);
        while st[j]>mid do dec(j);
        if i<=j then
        begin
            tmp:= st[i]; st[i]:= st[j]; st[j]:= tmp;
            inc(i); dec(j);
        end;
    until i>j;
    if i<r then sort(st,i,r);
    if l<j then sort(st,l,j);
end;

function modx(a,b:longint):longint;
begin
    if a<b then exit(a);
    if a mod b >0 then exit(a mod b);
    exit(b);
end;

procedure build;
begin
    kmu[0]:= 1;
    for i:= 1 to m+1 do
    kmu[i]:= min(kmu[i-1]*k,1000000001);
end;
procedure main;
begin

    //--------------------------
    count:= -1;
    for i:= n downto 1 do
    if st[i]='#' then
    begin
        inc(count);
        //writeln((modx(x,kmu[count+1])+kmu[count]-1) div kmu[count]);
        st[i]:=hash[m-count][(modx(x,kmu[count+1])+kmu[count]-1) div kmu[count]];
    end;
end;
begin
    start;
    build;
    for i:= 1 to m do sort(hash[i],1,k);
    main;
    writeln(fo,st);
    close(fi); close(fo);
end.
