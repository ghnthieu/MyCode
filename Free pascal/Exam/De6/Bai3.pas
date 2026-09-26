Program bai3;
var n:integer;
procedure xuly;
var fi,fo:text;
begin
  assign(fi,'Dulieu.inp');reset(fi);
  assign(fo,'Ketqua.out');rewrite(fo);
  read(fi,n);
  if n mod 2=0 then
    write(fo,n,' la so chan')
  else
    write(fo,n,' la so le');
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
