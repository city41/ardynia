// prefer default export if available
const preferDefault = m => m && m.default || m

exports.components = {
  "component---node-modules-gatsby-plugin-offline-app-shell-js": () => import("/home/matt/dev/ardynia/web/node_modules/gatsby-plugin-offline/app-shell.js" /* webpackChunkName: "component---node-modules-gatsby-plugin-offline-app-shell-js" */),
  "component---src-pages-404-js": () => import("/home/matt/dev/ardynia/web/src/pages/404.js" /* webpackChunkName: "component---src-pages-404-js" */),
  "component---src-pages-contact-js": () => import("/home/matt/dev/ardynia/web/src/pages/contact.js" /* webpackChunkName: "component---src-pages-contact-js" */),
  "component---src-pages-help-js": () => import("/home/matt/dev/ardynia/web/src/pages/help.js" /* webpackChunkName: "component---src-pages-help-js" */),
  "component---src-pages-index-js": () => import("/home/matt/dev/ardynia/web/src/pages/index.js" /* webpackChunkName: "component---src-pages-index-js" */)
}

exports.data = () => import("/home/matt/dev/ardynia/web/.cache/data.json")

