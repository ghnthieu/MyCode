Program thungnuoc;
var n:qword;
procedure xuly;
var fi,fo:text;
    t4,t1,t:qword;
begin
  assign(fi,'dulieu.inp');reset(fi);
  assign(fo,'ketqua.out');rewrite(fo);
  read(fi,n);
  t:=n div 5;
  t4:=t+((n mod 5) div 4);
  t1:=t+((n mod 5) mod 4);
  write(fo,t1+t4,' ',t4,' ',t1);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.

