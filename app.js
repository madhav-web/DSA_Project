const express = require("express");

const app = express();
const port = 3000;

app.set("view engine", "ejs");
app.use(express.static("public"));

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`);
});
//routes
app.get("/", (req, res) => {
  res.render("index");
});
app.get("/user/login", (req, res) => {
  res.render("userLogin");
});
//this must be at bottom
app.use(function (req, res) {
  res.status(404).render("404");
});
