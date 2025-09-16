return {
  vim.api.nvim_create_user_command("Hardcopy", function()
    vim.cmd("silent! call TOhtml()")
    vim.cmd("silent! !firefox % &")
  end, {}),
}
