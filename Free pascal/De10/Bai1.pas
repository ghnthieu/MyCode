Program ocsen;
var a,b,v:byte;
procedure xuly;
var fi,fo:text;
    dem,t:byte;
    qd:integer;
begin
  assign(fi,'Ocsen.inp');reset(fi);
  assign(fo,'Ocsen.out');rewrite(fo);
  read(fi,a,b,v);
  dem:=0;
  t:=0;
  qd:=0;
  while t+a<v do
    begin
      t:=t+a-b;
      inc(dem);
      qd:=qd+a+b;
    end;
  if t+a=v then
    begin
      qd:=qd+a;
      inc(dem);
    end
  else
    begin
      inc(dem);
      qd:=qd+v-t;
    end;
  write(fo,dem,' ',qd);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
