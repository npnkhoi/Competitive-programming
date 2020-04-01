var fi,fo:text;
    s:string;
    n,i,t,j,tc,loop:integer;
    ok: boolean;
procedure start;
begin
    assign(fi,'tidynum.inp'); reset(fi);
    assign(fo,'tidynum.out'); rewrite(fo);
    readln(fi,tc);
end;
procedure finish;
begin
    close(fi); close(fo); halt;
end;
procedure main;
begin
    n:= length(s);
    for i:= n-1 downto 1 do
    if s[i]>s[i+1] then
    begin
        ok:= true; s[i]:= chr(ord(s[i])-1);
        for j:= 2 to i do if s[j-1]>s[j] then ok:= false;
        if ok then
        begin
                for j:= 1 to i-1 do write(fo,s[j]);
                t:= ord(s[i])-49;
                if t>0 then write(fo,t);
                for j:= i+1 to n do write(fo,9);
                writeln(fo);
                exit;
        end;
        s[i]:= chr(ord(s[i])-47);
    end;
    for i:= 1 to n-1 do write(fo,9); writeln(fo);
end;
begin
    start;
    for loop:= 1 to tc do
    begin
        readln(fi,s);
        write(fo,'Case #',loop,': ');
        if length(s)=1 then writeln(fo,s)
        else main;
    end;
    finish;
end.
