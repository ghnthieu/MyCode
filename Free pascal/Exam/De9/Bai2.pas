Program bl2;
var n,k,p:longint;
procedure xuly;
var tien:qword;
    fi,fo:text;
begin
  assign(fi,'bl2.inp');reset(fi);
  assign(fo,'bl2.out');rewrite(fo);
  read(fi,n,p,k);
  tien:=0;
  tien:=(n-n div (k+1))*p;
  write(fo,tien);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
