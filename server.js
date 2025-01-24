// express
const express = require('express')
const app = express()

// server static files from /public
app.use(express.static('public'))

// start server
app.listen(2222, () => console.log('server running on port 2222'))
