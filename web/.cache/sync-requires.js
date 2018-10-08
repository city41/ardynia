// prefer default export if available
const preferDefault = m => m && m.default || m


exports.components = {
  "component---node-modules-gatsby-plugin-offline-app-shell-js": preferDefault(require("/home/matt/dev/ardynia/web/node_modules/gatsby-plugin-offline/app-shell.js")),
  "component---src-pages-404-js": preferDefault(require("/home/matt/dev/ardynia/web/src/pages/404.js")),
  "component---src-pages-contact-js": preferDefault(require("/home/matt/dev/ardynia/web/src/pages/contact.js")),
  "component---src-pages-help-js": preferDefault(require("/home/matt/dev/ardynia/web/src/pages/help.js")),
  "component---src-pages-index-js": preferDefault(require("/home/matt/dev/ardynia/web/src/pages/index.js"))
}

