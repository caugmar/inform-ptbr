return {
  "phrmendes/todotxt.nvim",
  cmd = { "TodoTxt", "DoneTxt" },
  opts = {
    todotxt = "path/to/the/todo.txt",
    donetxt = "path/to/the/done.txt",
    ghost_text = {
      enable = true,
      mappings = {
        ["(A)"] = "now",
        ["(B)"] = "next",
        ["(C)"] = "today",
      },
    },
  },
}
