Fields FieldsOperations;
Fields::vectorField2d U(mesh2d_.nrows, vector<Fields>(ny));
Fields::vectorField2d Unew(mesh2d_.nrows, vector<Fields>(ny));
Fields::vectorField2d V(mesh2d_.nrows, vector<Fields>(ny));
Fields::vectorField2d Vnew(mesh2d_.nrows, vector<Fields>(ny));
Fields::vectorField2d P(mesh2d_.nrows, vector<Fields>(ny));
Fields::vectorField2d Pnew(mesh2d_.nrows, vector<Fields>(ny));
Fields::vectorField2d b(mesh2d_.nrows, vector<Fields>(ny));

U = FieldsOperations.pass2DGridinfomation(U, mesh2d_.xpts, mesh2d_.ypts);
Unew = FieldsOperations.pass2DGridinfomation(Unew, mesh2d_.xpts, mesh2d_.ypts);
V = FieldsOperations.pass2DGridinfomation(V, mesh2d_.xpts, mesh2d_.ypts);
Vnew = FieldsOperations.pass2DGridinfomation(Vnew, mesh2d_.xpts, mesh2d_.ypts);
P = FieldsOperations.pass2DGridinfomation(P, mesh2d_.xpts, mesh2d_.ypts);
Pnew = FieldsOperations.pass2DGridinfomation(Pnew, mesh2d_.xpts, mesh2d_.ypts);
b = FieldsOperations.pass2DGridinfomation(b, mesh2d_.xpts, mesh2d_.ypts);
