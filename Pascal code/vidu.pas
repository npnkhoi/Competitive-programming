var f,g:text;
a,b,S:longint;
begin
        assign(f,'text.inp');
        assign(g,'text.out');
        reset(f);rewrite(g);
        while not(eof(f)) do
        begin
                b:=0;S:=0;
                while not(eoln(f)) do
                begin
                        read(f,a);
                        b:=b+1;
                        S:=S+a;
                end;
                readln(f);
                writeln(g,b,' ',s);
        end;
        close(f);close(g);
end.
