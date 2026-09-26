Program daoso;
var n:qword;
procedure xuly;
var t,tn:qword;
    fi,fo:text;
begin
  assign(fi,'dulieu.inp');reset(fi);
  assign(fo,'ketqua.out');rewrite(fo);
  read(fi,n);
  t:=n;
  tn:=0;
  while n<>0 do
    begin
      tn:=tn*10+(n mod 10);
      n:=n div 10;
    end;
  if tn=t then
    write(fo,tn,' =')
  else
    if tn>t then
      write(fo,tn,' >')
    else
      if tn<t then
        write(fo,tn,' <');
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
